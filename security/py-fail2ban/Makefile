# New ports collection makefile for:	fail2ban
# Date created:				13 January 2009
# Whom:					    Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	fail2ban
PORTVERSION=	0.8.4
CATEGORIES=	security python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tony@pc-tony.com
COMMENT=	scans log files and bans IP that makes too many password failures. 

MAKE_JOBS_SAFE= yes

USE_BZIP2=	yes

USE_PYTHON=	2.5-2.6
USE_PYDISTUTILS=	yes

USE_RC_SUBR=	fail2ban
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PYDISTUTILS_INSTALLARGS+=	--install-purelib=${PYTHON_SITELIBDIR} \
				--install-data=${ETCDIR} 

FILES=	${WRKSRC}/fail2ban-regex \
		${WRKSRC}/man/fail2ban-client.1 \
		${WRKSRC}/man/fail2ban-client.h2m \
		${WRKSRC}/setup.py \
		${WRKSRC}/client/configreader.py \
		${WRKSRC}/fail2ban-client

post-patch:
	@${ECHO_CMD} ${FILES} | ${XARGS} ${REINPLACE_CMD} -e 's,/etc/fail2ban,${ETCDIR},g'

.include <bsd.port.mk>
