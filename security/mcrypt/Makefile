# New ports collection makefile for:	mcrypt
# Date created:        			2000-12-31
# Whom:					trevor
# based on the OpenBSD port
#
# $OpenBSD: Makefile,v 1.1.1.1 2000/11/27 15:56:03 avsm Exp $
# $FreeBSD$
#

PORTNAME=	mcrypt
PORTVERSION=	2.6.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://argeas.cs-net.gr/pub/unix/mcrypt/attic/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/attic/
MASTER_SITE_SUBDIR=	mcrypt

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Replacement for crypt(1)

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt/ \
		mhash.2:${PORTSDIR}/security/mhash/

WANT_AUTOCONF_VER=	259
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	${CONFIGURE_SHARED}
CONFIGURE_ARGS+=	--enable-static --with-catgets
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=		yes
DOCS=			FORMAT magic
MAN1=			mcrypt.1
PKGMESSAGE=		${WRKDIR}/pkg-message
PLIST=			${WRKDIR}/pkg-plist

# to avoid having to read the configure script
pre-configure:
	cd ${WRKSRC} && ${RM} configure && ${AUTOCONF}

pre-install:
	${ECHO_CMD} bin/${PORTNAME} > ${PLIST}
.for i in cs de el es_AR pl
	${ECHO_CMD} share/locale/${i}/LC_MESSAGES/mcrypt.mo >> ${PLIST}
	${ECHO_CMD} @unexec rmdir %D/share/locale/${i}/LC_MESSAGES '2>/dev/null | true' >> ${PLIST}
	${ECHO_CMD} @unexec rmdir %D/share/locale/${i} '2>/dev/null | true' >> ${PLIST}
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
.for i in cs de el es_AR pl
	${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.gmo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/mcrypt.mo
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc ${EXAMPLESDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc ${EXAMPLESDIR}/
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
