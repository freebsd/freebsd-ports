# $FreeBSD$

PORTNAME=	fail2ban
PORTVERSION=	0.9.4
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	theis@gmx.at
COMMENT=	Scans log files and bans IP that makes too many password failures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

USES=		python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	fail2ban

NO_ARCH=	yes

SHEBANG_FILES=	config/filter.d/ignorecommands/apache-fakegooglebot

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-data=${ETCDIR}

PORTDOCS=	README.md DEVELOP

FILES=		${WRKSRC}/bin/fail2ban-client \
		${WRKSRC}/fail2ban/client/configreader.py \
		${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/setup.py
FAIL2BAN_DBDIR=	/var/db/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/fail2ban,${ETCDIR},g' ${FILES}
	@${REINPLACE_CMD} -e 's,paths-debian.conf,paths-freebsd.conf,g' \
		${WRKSRC}/config/jail.conf
	@${REINPLACE_CMD} -e 's,/var/lib/fail2ban/,${FAIL2BAN_DBDIR}/,g' \
		${WRKSRC}/config/fail2ban.conf

post-install:
	@${MKDIR} ${STAGEDIR}${FAIL2BAN_DBDIR} ${STAGEDIR}/var/run/fail2ban
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.for file in fail2ban-client fail2ban-regex fail2ban-server fail2ban
	${INSTALL_MAN} ${WRKSRC}/man/${file}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/jail.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5/fail2ban-jail.conf.5

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
