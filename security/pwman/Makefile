# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwman
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console password management application based on gpg(me)

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-return-type

PLIST_FILES=	bin/convert_pwdb bin/pwdb2csv bin/pwman man/man1/pwman.1.gz
PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gpg|${LOCALBASE}/bin/gpg|g' ${WRKSRC}/src/options.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
