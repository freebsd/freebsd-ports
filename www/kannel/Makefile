# New ports collection makefile for:   kannel
# Date created:		19 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.4.0
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.org/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	gateway-${PORTVERSION}

PATCH_SITES=		http://www.mbuni.org/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAP / SMS Gateway

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cflags="${CPPFLAGS}" --with-libs="${LDFLAGS}" \
		--enable-pcre=yes --enable-docs=no --with-malloc=native \
		--enable-start-stop-daemon=no

.if defined(WITH_MBUNI_FULL)
PATCHFILES+=	mbuni-kannel-patch-full
.endif

.if defined(WITH_MBUNI_MINIMAL)
PATCHFILES+=	mbuni-kannel-patch-minimal
.endif

MAN1=		mtbatch.1 seewbmp.1 wmlsc.1 wmlsdasm.1
MAN8=		kannel.8 run_kannel_box.8

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" || ${ARCH} == "sparc64"
BROKEN=		"Does not compile on alpha or sparc64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g ; \
		 s|-lc_r||g ; \
		 s|-lkse||g' ${WRKSRC}/configure

post-install:
.for file in wapkannel.conf smskannel.conf
	${INSTALL_DATA} ${WRKSRC}/gw/${file} ${PREFIX}/etc/${file}.sample
.endfor
.for file in mtbatch seewbmp wmlsc wmlsdasm
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.for file in bearerbox run_kannel_box smsbox wapbox
	@${STRIP_CMD} ${PREFIX}/sbin/${file}
.endfor

.include <bsd.port.post.mk>
