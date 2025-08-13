PORTNAME=	fail2ban
DISTVERSION=	1.1.0
PORTREVISION=	6
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Scans log files and bans IP that makes too many password failures
WWW=		https://www.fail2ban.org/wiki/index.php/Main_Page

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cpe python:patch,run shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
PYDISTUTILS_BUILDARGS+=	--without-tests
PYDISTUTILS_INSTALLARGS+=	--install-data=${ETCDIR}
USE_RC_SUBR=	fail2ban

SHEBANG_FILES=	config/filter.d/ignorecommands/apache-fakegooglebot
SHEBANG_LANG=	fail2ban-python

NO_ARCH=	yes
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PORTDOCS=	DEVELOP README.md

OPTIONS_DEFINE=		DOCS INOTIFY
OPTIONS_DEFAULT=	INOTIFY

INOTIFY_DESC=	Support for (lib)inotify to monitor filesystem changes

INOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyinotify>=0.8.3:devel/py-pyinotify@${PY_FLAVOR}

FILES=		${WRKSRC}/bin/fail2ban-client \
		${WRKSRC}/fail2ban/client/configreader.py \
		${WRKSRC}/fail2ban/client/fail2bancmdline.py \
		${WRKSRC}/fail2ban/client/fail2banregex.py \
		${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m ${WRKSRC}/setup.py

MAN_FILES=	${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/man/fail2ban-regex.1 ${WRKSRC}/man/fail2ban-server.1 \
		${WRKSRC}/man/fail2ban.1

FAIL2BAN_DBDIR=	/var/db/${PORTNAME}
PLIST_SUB=	FAIL2BAN_DBDIR=${FAIL2BAN_DBDIR}

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARG=	--no-diffs --write --nobackups --fix=all

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
	@${RM} ${WRKSRC}/config/filter.d/sshd.conf

	# XXX Ideally this should be in do-build but it only works in
	# XXX post-patch
	(cd ${WRKSRC}/ && ${PY2TO3_CMD} ${PY2TO3_ARG} bin/* fail2ban)

post-install:
	@${MKDIR} ${STAGEDIR}${FAIL2BAN_DBDIR} ${STAGEDIR}/var/run/fail2ban
.for file in fail2ban-client fail2ban-regex fail2ban-server fail2ban
	${INSTALL_MAN} ${WRKSRC}/man/${file}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/jail.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/fail2ban-jail.conf.5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${RM} ${STAGEDIR}/${ETCDIR}/filter.d/selinux-sshd.conf

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
