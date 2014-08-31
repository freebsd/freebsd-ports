# Created by: Gavin McDonald <gavin@16degrees.com.au>
# $FreeBSD$

PORTNAME=	orthrus
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE  \
		http://16degrees.com.au/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	One-Time Password System (OTP) alternative to OPIE or S/Key

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:${PORTSDIR}/devel/apr1

USES=		iconv scons tar:bzip2
MAKE_ARGS=	DEBUG=False --install-sandbox=${STAGEDIR}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O[0-9]|| ; \
		 /chmod/d' ${WRKSRC}/SConstruct

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} NOTICE README TODO \
		${STAGEDIR}${DOCSDIR})
	@${ECHO_CMD} -n > ${STAGEDIR}${PREFIX}/etc/orthruskeys
.for i in bin/ortcalc bin/ortpasswd lib/liborthrus-0.so \
	lib/security/pam_orthrus.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${i}
.endfor

.include <bsd.port.mk>
