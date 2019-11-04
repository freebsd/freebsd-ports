# Created by: Talal Al-Dik <tad@vif.com>
# $FreeBSD$

PORTNAME=	archmbox
PORTVERSION=	4.10.0
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	SF/adc-${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email archiver that parses mailboxes and performs actions

LICENSE=	GPLv2

USES=		perl5
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

post-patch:
# Linux fuser(1) is incompatible with FreeBSD one, do not look for it
	@${REINPLACE_CMD} -e '/for ac_prog in/s, fuser,,' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
