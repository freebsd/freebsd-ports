# New ports collection makefile for:	wmnd
# Date created:				29 October 2001
# Whom:					Paolo Pisati <flag@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	wmnd
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	http://www.hydra.ubiest.com/wmnd/releases/

MAINTAINER=	flag@gufi.org

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${EXAMPLESDIR}

MAN1=		wmnd.1

pre-patch:
.for m in Makefile.in doc/Makefile.in examples/Makefile.in src/Makefile.in
	@${PERL} -pi -e 's|\@program_transform_name\@||' ${WRKSRC}/${m}
.endfor
.for files in install-sh config.sub mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/automake/${files} \
		${WRKSRC}/${files}
.endfor

.include <bsd.port.mk>
