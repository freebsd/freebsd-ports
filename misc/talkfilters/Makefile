# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	talkfilters
PORTVERSION=	2.3.8
CATEGORIES=	misc
MASTER_SITES=	http://www.hyperrealm.com/talkfilters/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Set of filters to convert English text to various stereotyped dialects

LICENSE=	GPLv2

CONFLICTS=	jive* chef* filters-*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=	talkfilters

pre-everything::
	@${ECHO_MSG} "Please note that some of the filters contain language that may"
	@${ECHO_MSG} "be objectionable to some. They are provided uncensored, in their"
	@${ECHO_MSG} "original form. Please don't use the filters to do anything that"
	@${ECHO_MSG} "you shouldn't."

post-extract:
	@${ECHO} ${DO_NADA} > ${WRKSRC}/install-sh
	@${CHMOD} +x ${WRKSRC}/install-sh

post-patch:
	@${RM} -f ${WRKSRC}/*.info*
	@${REINPLACE_CMD} -e \
		's|^\(pkgconfigdir\ =\ \).*|\1$$(prefix)/libdata/pkgconfig|' \
			${WRKSRC}/Makefile.am \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
