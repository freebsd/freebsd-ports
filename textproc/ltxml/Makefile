# New ports collection makefile for:	LT XML
# Date created:		20 Oct 2000
# Whom:			Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	ltxml
PORTVERSION=	1.2.5
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/LTXML/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Toolkit

WRKSRC=		${WRKDIR}/${DISTNAME}/XML

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib=/usr --enable-multi-byte

MAN1=		ltxml.1 xmlnorm.1 pesis.1 sgcount.1 sggrep.1 sgmlsb.1 \
		sgmlseg.1 sgmltoken.1 sgmltrans.1 sgrpg.1 textonly.1 \
		unknit.1 sgsort.1 nslwhere.1 knit.1 nslshowddb.1 getindex.1
MAN5=		ltxml-query.5

PROGRAMS=	getindex intersect knit nslshowddb nslwhere pesis sgcount \
		sggrep sgmlsb sgmlseg sgmltrans sgrpg sgsort simple simpleq \
		textonly unknit xmlnorm

post-patch:
	@${PERL} -pi -e 's|CFLAGS=.*$$|CFLAGS=\$$CFLAGS|g ; \
		 s|CXXFLAGS=.*$$|CXXFLAGS=\$$CXXFLAGS|g' ${WRKSRC}/configure

post-install:
.for file in ${PROGRAMS:S/sgmlseg//}
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
