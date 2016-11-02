# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mboxgrep
PORTVERSION=	0.7.9
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase ssl
GNU_CONFIGURE=	yes

CFLAGS+=	-I${OPENSSLINC}
LIBS+=		-L${OPENSSLLIB}

INFO=		mboxgrep

PORTDOCS=	ChangeLog NEWS README TODO
PLIST_FILES=	bin/mboxgrep \
		man/man1/mboxgrep.1.gz

OPTIONS_DEFINE=	DOCS PCRE

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

post-patch:
	@${REINPLACE_CMD} -e 's,void \*tmpp,FILE \*tmpp,g' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's,$$(prefix),$$(DESTDIR)$$(prefix),g' \
		-e 's,$$(mandir),$$(DESTDIR)$$(mandir),g' \
		-e 's,$$(infodir),$$(DESTDIR)$$(infodir),g' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/doc/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
