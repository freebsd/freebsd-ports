# New ports collection makefile for:	mcrypt
# Date created:        			2000-12-31
# Whom:					trevor
# based on the OpenBSD port
#
# $OpenBSD: Makefile,v 1.1.1.1 2000/11/27 15:56:03 avsm Exp $
# $FreeBSD$
#

PORTNAME=	mcrypt
PORTVERSION=	2.5.6
CATEGORIES=    	security
MASTER_SITES=	ftp://argeas.cs-net.gr/pub/unix/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	mcrypt.6:${PORTSDIR}/security/libmcrypt/ \
		mhash.2:${PORTSDIR}/security/mhash/ \
		intl.1:${PORTSDIR}/devel/gettext/

post-patch:
	${RM} -f ${WRKSRC}/configure

CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
CONFIGURE_ARGS+=	--enable-static --with-catgets
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -lintl -lltdl"
MAN1=			mcrypt.1
PLIST=			${WRKDIR}/pkg-plist
USE_AUTOCONF=		yes
USE_LIBTOOL=		yes

pre-install:
	${ECHO_CMD} bin/${PORTNAME} > ${PLIST}
	${ECHO_CMD} bin/mdecrypt >> ${PLIST}
.for i in cs el pl
	${ECHO_CMD} share/locale/${i}/LC_MESSAGES/mcrypt.mo >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	${ECHO_CMD} share/examples/${PORTNAME}/sample.mcryptrc >> ${PLIST}
	${ECHO_CMD} @dirrm share/examples/${PORTNAME} >> ${PLIST}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc \
		${PREFIX}/share/examples/${PORTNAME}/
.endif

.include <bsd.port.mk>
