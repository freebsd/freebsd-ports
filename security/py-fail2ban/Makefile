# $FreeBSD$

PORTNAME=	fail2ban
PORTVERSION=	0.9.2
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	theis@gmx.at
COMMENT=	Scans log files and bans IP that makes too many password failures

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_GITHUB=	yes

USES=		python
USE_PYTHON=	distutils py3kplist

USE_RC_SUBR=	fail2ban
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-purelib=${PYTHON_SITELIBDIR} \
				--install-data=${ETCDIR}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}

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
	@${REINPLACE_CMD} -e 's,/var/lib/fail2ban/fail2ban.sqlite3,${FAIL2BAN_DBDIR}/fail2ban.sqlite3,g' \
		${WRKSRC}/config/fail2ban.conf

post-install:
	@${MKDIR} ${STAGEDIR}${FAIL2BAN_DBDIR} ${STAGEDIR}/var/run/fail2ban
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.for file in fail2ban-client fail2ban-regex fail2ban-server fail2ban
	${INSTALL_MAN} ${WRKSRC}/man/${file}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/jail.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5/fail2ban-jail.conf.5

.include <bsd.port.mk>
