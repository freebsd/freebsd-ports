# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mboxgrep
PORTVERSION=	0.7.9
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USE_OPENSSL=	yes

INFO=		mboxgrep

DOCS=		ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS PCRE

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

post-patch:
	@${REINPLACE_CMD} -e 's,void \*tmpp,FILE \*tmpp,g' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's,$$(prefix),$$(DESTDIR)$$(prefix),g' \
		-e 's,$$(mandir),$$(DESTDIR)$$(mandir),g' \
		-e 's,$$(infodir),$$(DESTDIR)$$(infodir),g' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
