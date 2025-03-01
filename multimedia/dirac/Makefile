PORTNAME=	dirac
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-codec/Dirac-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Open source video codec from the BBC
WWW=		https://dirac.sourceforge.net/

DEPRECATED=	Legacy video codec superseded by multiple formats. Files can be decoded using FFmpeg
EXPIRATION_DATE=2025-03-31

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix shebangfix
SHEBANG_FILES=	${WRKSRC}/tests/create_dirac_testfile.pl
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-mmx
CONFIGURE_ENV=	HAVE_LATEX=${FALSE} HAVE_DVIPDFM=${FALSE} \
		HAVE_DOXYGEN=${FALSE} HAVE_DOT=${FALSE}
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-std=c++98

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.include <bsd.port.mk>
