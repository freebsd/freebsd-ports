# New ports collection makefile for:	webcpp
# Date created:		12 May 2003
# Whom:			Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	webcpp
PORTVERSION=	0.8.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	chip-set@mail.ru
COMMENT=	Convert you source code to syntax highlighted HTML

USE_GCC=	3.2
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_REINPLACE=	yes

.if defined(WANT_FINAL)
CONFIGURE_ARGS+=	--enable-final
USE_GMAKE=	yes
.endif

pre-patch:
	${FIND} ${WRKSRC} -name '*.h' | ${XARGS} ${REINPLACE_CMD} \
		's|IO->close()|if(IO) IO->close()|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING README TODO docs.html
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
