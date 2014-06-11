# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mboxgrep
PORTVERSION=	0.7.9
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression

.if defined(WITH_PCRE)
LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre
.endif

USES=		uidfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USE_OPENSSL=	yes

INFO=		mboxgrep

DOCS=		ChangeLog NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's,void \*tmpp,FILE \*tmpp,g' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's,$$(prefix),$$(DESTDIR)$$(prefix),g' \
		-e 's,$$(mandir),$$(DESTDIR)$$(mandir),g' \
		-e 's,$$(infodir),$$(DESTDIR)$$(infodir),g' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
