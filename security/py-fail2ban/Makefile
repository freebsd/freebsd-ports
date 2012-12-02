# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	fail2ban
PORTVERSION=	0.8.7.1
CATEGORIES=	security python
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	theis@gmx.at
COMMENT=	Scans log files and bans IP that makes too many password failures

LICENSE=	GPLv2

GITVERSION=	0-g0b5c66f
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-e59babb

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

USE_RC_SUBR=	fail2ban
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-purelib=${PYTHON_SITELIBDIR} \
				--install-data=${ETCDIR}
PYDISTUTILS_PKGVERSION=	0.8.7

FILES=	${WRKSRC}/fail2ban-regex \
		${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/setup.py \
		${WRKSRC}/client/configreader.py \
		${WRKSRC}/fail2ban-client

post-patch:
	@${ECHO_CMD} ${FILES} | ${XARGS} ${REINPLACE_CMD} -e 's,/etc/fail2ban,${ETCDIR},g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
