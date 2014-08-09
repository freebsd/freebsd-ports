# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwman
PORTVERSION=	0.4.4
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console password management application based on gpg(me)

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README TODO
PLIST_FILES=	bin/convert_pwdb bin/pwdb2csv bin/pwman man/man1/pwman.1.gz

CFLAGS+=	-Wno-error=return-type

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/src/options.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
