# New ports collection makefile for:	mimms
# Date created:		3 Jul 2007
# Whom:                	Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	mimms
DISTVERSION=	3.2.1
CATEGORIES=	multimedia net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	Download streams using the MMS protocol

LIB_DEPENDS=	mms.0:${PORTSDIR}/net/libmms

USE_BZIP2=	yes

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_PKGVERSION=	3.2

MAN1=		mimms.1
PORTDOCS=	AUTHORS COPYING NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
