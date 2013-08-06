# Created by: Talal Al-Dik <tad@vif.com>
# $FreeBSD$

PORTNAME=	archmbox
PORTVERSION=	4.10.0
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	SF/adc-${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	tad@vif.com
COMMENT=	Email archiver that parses mailboxes and performs actions

LICENSE=	GPLv2

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"

MAN1=		archmbox.1
PLIST_FILES=	bin/archmbox
PORTDOCS=	ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# Linux fuser(1) is incompatible with FreeBSD one, do not look for it
	@${REINPLACE_CMD} -e '/for ac_prog in/s, fuser,,' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
