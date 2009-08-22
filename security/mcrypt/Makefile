# New ports collection makefile for:	mcrypt
# Date created:        			2000-12-31
# Whom:					trevor
# based on the OpenBSD port
#
# $OpenBSD: Makefile,v 1.1.1.1 2000/11/27 15:56:03 avsm Exp $
# $FreeBSD$
#

PORTNAME=	mcrypt
PORTVERSION=	2.6.8
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/MCrypt/${PORTVERSION} \
		ftp://argeas.cs-net.gr/pub/unix/mcrypt/attic/ \
		ftp://ftp.ntua.gr/pub/security/mcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/attic/

MAINTAINER=	johans@stack.nl
COMMENT=	Replacement for crypt(1)

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--enable-static --with-catgets

MAN1=		mcrypt.1
PORTDOCS=	FORMAT magic
PLIST_FILES=	bin/mcrypt \
		%%EXAMPLESDIR%%/sample.mcryptrc \
		share/locale/cs/LC_MESSAGES/mcrypt.mo \
		share/locale/de/LC_MESSAGES/mcrypt.mo \
		share/locale/el/LC_MESSAGES/mcrypt.mo \
		share/locale/es_AR/LC_MESSAGES/mcrypt.mo \
		share/locale/pl/LC_MESSAGES/mcrypt.mo
PLIST_DIRS=	%%EXAMPLESDIR%%

PLIST=		${WRKDIR}/pkg-plist

post-patch:
	${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/src/rfc2440.c

pre-install:
.for i in es_AR
	@${ECHO_CMD} "@dirrmtry share/locale/${i}/LC_MESSAGES" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/locale/${i}" >> ${PLIST}
.endfor

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
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.mcryptrc ${EXAMPLESDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in FORMAT magic
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
