# New ports collection makefile for:	mboxgrep
# Date created:				28 October 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mboxgrep
PORTVERSION=	0.7.9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Utility to scan mailboxes for messages matching a regular expression

.if defined(WITH_PCRE)
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

MAN1=		mboxgrep.1
INFO=		mboxgrep

DOCS=		ChangeLog NEWS README TODO

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
