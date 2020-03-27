# $FreeBSD$

PORTNAME=	fail2ban
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	theis@gmx.at
COMMENT=	Scans log files and bans IP that makes too many password failures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:patch shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	fail2ban

NO_ARCH=	yes

SHEBANG_FILES=	config/filter.d/ignorecommands/apache-fakegooglebot
SHEBANG_LANG=	fail2ban-python

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-data=${ETCDIR} --without-test

PORTDOCS=	README.md DEVELOP

OPTIONS_DEFINE=	DOCS INOTIFY
OPTIONS_DEFAULT=INOTIFY

INOTIFY_DESC=		Support for (lib)inotify to monitor filesystem changes

INOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyinotify>=0.8.3:devel/py-pyinotify@${PY_FLAVOR}

FILES=		${WRKSRC}/bin/fail2ban-client \
		${WRKSRC}/fail2ban/client/configreader.py \
		${WRKSRC}/fail2ban/client/fail2bancmdline.py \
		${WRKSRC}/fail2ban/client/fail2banregex.py \
		${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/setup.py

MAN_FILES=	${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/man/fail2ban-regex.1 \
		${WRKSRC}/man/fail2ban-server.1 \
		${WRKSRC}/man/fail2ban.1

FAIL2BAN_DBDIR=	/var/db/${PORTNAME}

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARG=	--no-diffs --write --nobackups --fix=all

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/fail2ban,${ETCDIR},g' ${FILES}
	@${REINPLACE_CMD} -e 's,paths-debian.conf,paths-freebsd.conf,g' \
		${WRKSRC}/config/jail.conf
	@${REINPLACE_CMD} -e 's,/var/lib/fail2ban/,${FAIL2BAN_DBDIR}/,g' \
		${WRKSRC}/config/fail2ban.conf
	@${REINPLACE_CMD} -e 's,jail.conf(5),fail2ban-jail.conf(5),g' \
		${MAN_FILES}
	@${REINPLACE_CMD} -e 's, sed , ${SED} ,g' \
		${WRKSRC}/config/action.d/hostsdeny.conf

.	if ${PYTHON_MAJOR_VER} >= 3
		(cd ${WRKSRC}/ && ${PY2TO3_CMD} ${PY2TO3_ARG} bin/* fail2ban)
.	endif

post-install:
	@${MKDIR} ${STAGEDIR}${FAIL2BAN_DBDIR} ${STAGEDIR}/var/run/fail2ban
.for file in fail2ban-client fail2ban-regex fail2ban-server fail2ban
	${INSTALL_MAN} ${WRKSRC}/man/${file}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/jail.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5/fail2ban-jail.conf.5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
