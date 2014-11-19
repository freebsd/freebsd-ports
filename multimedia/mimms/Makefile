# Created by: Yinghong.Liu <liu_yinghong@yahoo.com.cn>
# $FreeBSD$

PORTNAME=	mimms
DISTVERSION=	3.2.1
CATEGORIES=	multimedia net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	Download streams using the MMS protocol

LIB_DEPENDS=	libmms.so:${PORTSDIR}/net/libmms

USES=		python tar:bzip2
USE_PYTHON=	distutils
PYDISTUTILS_PKGVERSION=	3.2

PORTDOCS=	AUTHORS COPYING NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
