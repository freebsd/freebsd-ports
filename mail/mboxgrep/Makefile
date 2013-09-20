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

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include
USE_OPENSSL=	yes

MAN1=		mboxgrep.1
INFO=		mboxgrep

DOCS=		ChangeLog NEWS README TODO

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,void \*tmpp,FILE \*tmpp,g' ${WRKSRC}/src/main.c

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
