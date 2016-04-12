# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	courierpassd
PORTVERSION=	1.1.2
CATEGORIES=	security mail
MASTER_SITES=	http://www.arda.homeunix.net/software-downloads/ \
		LOCAL/ade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User authentication and password changing daemon utility

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	courierauthconfig:security/courier-authlib-base
RUN_DEPENDS=	courierauthconfig:security/courier-authlib-base

GNU_CONFIGURE=	yes
USES=		gmake localbase

MINUID?=	100
DELAY?=		3
CONFIGURE_ARGS+=--with-minuid=${MINUID} --with-badpassdelay=${DELAY}

PLIST_FILES=	sbin/courierpassd man/man8/courierpassd.8.gz
PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL NEWS README

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO}
	@${ECHO} "###########################################################"
	@${ECHO}
	@${ECHO} "The following build options are available:"
	@${ECHO}
	@${ECHO} "  MINUID=uid"
	@${ECHO} "	Accounts with uids below this value cannot have"
	@${ECHO} "	their passwords changed. Default value is 100."
	@${ECHO}
	@${ECHO} "  DELAY=sec"
	@${ECHO} "	Set the delay after a password change failure."
	@${ECHO} "	Default is 3 seconds."
	@${ECHO}
	@${ECHO} "###########################################################"
	@${ECHO}

post-patch:
	@${REINPLACE_CMD} '/chown root/d' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
