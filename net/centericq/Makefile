# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	4.8.7
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv \
		sigc.1:${PORTSDIR}/devel/libsigc++
#		fribidi.0:${PORTSDIR}/converters/fribidi

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lstdc++"
#CONFIGURE_ARGS=	--with-fribidi

MAN1=	centericq.1

post-patch:
.for file in kkconsui-0.1/include/conf.h kkstrtext-0.1/conf.h kksystr-0.1/include/conf.h
	@(cd ${WRKSRC} ; \
	  ${MV} -f ${file} ${file}.orig ; \
	  ${GREP} -v "_G_config.h" ${file}.orig > ${file})
.endfor
		
.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} FAQ README ${DOCSDIR})
.endif

.include <bsd.port.mk>
