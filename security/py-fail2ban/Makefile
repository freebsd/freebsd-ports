# $FreeBSD$

PORTNAME=	fail2ban
PORTVERSION=	0.8.11
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	theis@gmx.at
COMMENT=	Scans log files and bans IP that makes too many password failures

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	fc213a1
GH_TAGNAME=	${PORTVERSION}

USE_PYTHON=	2
USE_PYDISTUTILS=	yes

USE_RC_SUBR=	fail2ban
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-purelib=${PYTHON_SITELIBDIR} \
				--install-data=${ETCDIR}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}

PORTDOCS=	README.md DEVELOP

FILES=	${WRKSRC}/fail2ban-regex \
		${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/setup.py \
		${WRKSRC}/client/configreader.py \
		${WRKSRC}/fail2ban-client

.include <bsd.port.options.mk>

post-patch:
	@${ECHO_CMD} ${FILES} | ${XARGS} ${REINPLACE_CMD} -e 's,/etc/fail2ban,${ETCDIR},g'
	@${REINPLACE_CMD} -e 's,/bin/grep,grep,g' \
		${WRKSRC}/config/action.d/sendmail-whois-lines.conf
	@${REINPLACE_CMD} -e 's,/var/log/sshd.log,/var/log/auth.log,g' \
		${WRKSRC}/config/jail.conf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
