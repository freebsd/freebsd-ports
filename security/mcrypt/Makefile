# New ports collection makefile for:	mcrypt
# Date created:        			2000-12-31
# Whom:					trevor
# based on the OpenBSD port
#
# $OpenBSD: Makefile,v 1.1.1.1 2000/11/27 15:56:03 avsm Exp $
# $FreeBSD$
#

PORTNAME=	mcrypt
PORTVERSION=	2.5.13
CATEGORIES=    	security
MASTER_SITES=	ftp://argeas.cs-net.gr/pub/unix/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt/ \
		mhash.2:${PORTSDIR}/security/mhash/ \
		intl.4:${PORTSDIR}/devel/gettext

CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
CONFIGURE_ARGS+=	--enable-static --with-catgets
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -lintl -lltdl"
GNU_CONFIGURE=		yes
DOCS=			FORMAT magic
MAN1=			mcrypt.1
PKGMESSAGE=		${WRKDIR}/pkg-message
PLIST=			${WRKDIR}/pkg-plist

pre-configure:
	cd ${WRKSRC} && automake -i && autoconf

pre-install:
	${ECHO_CMD} bin/${PORTNAME} > ${PLIST}
.for i in cs el pl
	${ECHO_CMD} share/locale/${i}/LC_MESSAGES/mcrypt.mo >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	${ECHO_CMD} share/examples/${PORTNAME}/sample.mcryptrc >> ${PLIST}
	${ECHO_CMD} @dirrm share/examples/${PORTNAME} >> ${PLIST}
.for i in ${DOCS}
	${ECHO_CMD} share/doc/${PORTNAME}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/${PORTNAME} >> ${PLIST}
.endif
	${ECHO_CMD} "*** WARNING ***" > ${PKGMESSAGE}
	${ECHO_CMD} \
"The source for this package has not been reviewed by the FreeBSD maintainer." \
		>> ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mcrypt ${PREFIX}/bin/
.for i in el cs pl
	${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.gmo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/mcrypt.mo
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc ${EXAMPLESDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc ${EXAMPLESDIR}/
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
