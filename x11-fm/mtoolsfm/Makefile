# New ports collection makefile for:	MToolsFM
# Date created:				12 Jan 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mtoolsfm
PORTVERSION=	1.8
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/
DISTNAME=	MToolsFM-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-conffile="${PREFIX}/etc/mtoolsfm.conf" \
		--with-mtoolsdir="${LOCALBASE}/bin" \
		--disable-gtktest

MAN1=		mtoolsfm.1

post-patch:
	@${PERL} -pi -e 's|MToolsFM|mtoolsfm|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/MToolsFM.1
	@find ${WRKSRC} -name 'Makefile.in' | xargs ${PERL} -pi -e \
		's|MToolsFM|mtoolsfm|g'

pre-build:
	@${LN} -sf ${WRKSRC}/MToolsFM.1 ${WRKSRC}/mtoolsfm.1

.include <bsd.port.mk>
