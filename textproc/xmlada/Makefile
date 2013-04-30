# Created by: John Marino <draco@marino.st> 
# $FreeBSD$

PORTNAME=	xmlada
PORTVERSION=	4.2.0.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	draco@marino.st
COMMENT=	Adacore XML suite for the Ada language

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USES=		ada

LICENSE=		GPLv2
MAKE_JOBS_UNSAFE=	yes

# Link options were added for sax, dom, schema, and input_sources libraries
# "-R" option disables all rpaths except adalib and compiler libs.  This is
#      done because by default the rpaths will points at the WRKOBJDIR because
#      it doesn't support the concept of DESTDIR.
# "-Wl,-R" adds a second rpath string.
# -Wl,-rpath is a better choice, but synonym -Wl,-R works on all BSD and SunOS

post-patch:
	@${REINPLACE_CMD} -e "s,@ADDITIONAL_RPATH@,${LOCALBASE}/lib," \
	  ${WRKSRC}/sax/sax.gpr \
	  ${WRKSRC}/dom/dom.gpr \
	  ${WRKSRC}/schema/schema.gpr \
	  ${WRKSRC}/input_sources/input_sources.gpr

.include <bsd.port.mk>
