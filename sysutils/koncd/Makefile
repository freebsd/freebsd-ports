# New ports collection makefile for:	koncd
# Date created:				2 April 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koncd
PORTVERSION=	1.0r2
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.koncd.org/download/ \
		ftp://apps.kde.com/pub/Multimedia/Audio/Burners_Rippers/KOnCD/
DISTNAME=	${PORTNAME}-1.0rc2

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		mpg123:${PORTSDIR}/audio/mpg123

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.h' | ${XARGS} \
		${PERL} -pi -e 's|^.*#.*include.*<malloc\.h>.*||g'
	@${FIND} ${WRKSRC} -type f -name '*.cpp' | ${XARGS} \
		${PERL} -pi -e 's|^.*#.*include.*<malloc\.h>.*||g'

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.dist

.include <bsd.port.post.mk>
