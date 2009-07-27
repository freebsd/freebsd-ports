# New ports collection makefile for:   kannel
# Date created:		19 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.4.3
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.org/download/%SUBDIR%/ \
		http://farrokhi.net/distfiles/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAP / SMS Gateway

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_RC_SUBR=	kannel
USE_GNOME=	libxml2
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cflags="${CPPFLAGS}" --with-libs="${LDFLAGS}" \
		--enable-pcre=yes --enable-docs=no --with-malloc=native \
		--enable-start-stop-daemon=no

MAN1=		mtbatch.1 seewbmp.1 wmlsc.1 wmlsdasm.1
MAN8=		kannel.8 run_kannel_box.8

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g ; \
		 s|-lc_r||g ; \
		 s|-lkse||g' ${WRKSRC}/configure

post-install:
.for filename in wapkannel.conf smskannel.conf
	${INSTALL_DATA} ${WRKSRC}/gw/${filename} ${PREFIX}/etc/${filename}.sample
.endfor
.for filename in mtbatch seewbmp wmlsc wmlsdasm
	@${STRIP_CMD} ${PREFIX}/bin/${filename}
.endfor
.for filename in bearerbox run_kannel_box smsbox wapbox
	@${STRIP_CMD} ${PREFIX}/sbin/${filename}
.endfor

.include <bsd.port.post.mk>
