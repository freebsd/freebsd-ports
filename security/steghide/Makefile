# New ports collection makefile for:	steghide
# Date created:				26 February 2001
# Whom:					RaRa Rasputin <rasputin@submonkey.net>
#
# $FreeBSD$
#

PORTNAME=	steghide
PORTVERSION=	0.4.6.b
CATEGORIES=	security
MASTER_SITES=	http://steghide.sourceforge.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	arved@FreeBSD.org

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash \
		intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
USE_REINPLACE=	yes

MAN1=		steghide.1

post-patch:
.ifdef(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|install-data-am\: install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif
.for i in msg.h arg.h cvrstgfile.h error.h jpegjfifapp0.h
	${REINPLACE_CMD} -e 's/#include <string>//' ${WRKSRC}/src/${i}
	${REINPLACE_CMD} -e 's/string/std::string/g' ${WRKSRC}/src/${i}
.endfor
.for i in hash.cc bufmanag.cc wavfile.cc
	${REINPLACE_CMD} -e 's/string.h/string/' ${WRKSRC}/src/${i}
.endfor
.for i in jpeghufftable.h jpegbase.h jpegentropycoded.h jpegscan.h \
		jpegframe.h bmpfile.h aufile.h jpegunusedseg.h
	${REINPLACE_CMD} -e 's/#include <vector>//' ${WRKSRC}/src/${i}
	${REINPLACE_CMD} -e 's/vector/std::vector/g' ${WRKSRC}/src/${i}
.endfor

.include <bsd.port.mk>
