# Created by: Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	mod_authn_otp
PORTVERSION=	1.1.6
CATEGORIES=	www
MASTER_SITES=	http://mod-authn-otp.googlecode.com/files/ \
		http://alex.bmg.gv.at/programs/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Apache module for one-time password authentication

LICENSE=	APACHE20

USES=		ssl
GNU_CONFIGURE=	yes
USE_APACHE=	22+

CPPFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PORTEXAMPLES=	users.sample

OPTIONS_DEFINE=	EXAMPLES

post-configure:
	@${REINPLACE_CMD} 's|CFLAGS =|CFLAGS ?=|' \
		${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/${APACHEMODDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/users.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
