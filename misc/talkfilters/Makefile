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

MAN1=	talkfilters.1 wrap.1
MLINKS=	talkfilters.1 austro.1 \
	talkfilters.1 b1ff.1 \
	talkfilters.1 brooklyn.1 \
	talkfilters.1 chef.1 \
	talkfilters.1 cockney.1 \
	talkfilters.1 drawl.1 \
	talkfilters.1 dubya.1 \
	talkfilters.1 fudd.1 \
	talkfilters.1 funetak.1 \
	talkfilters.1 jethro.1 \
	talkfilters.1 jive.1 \
	talkfilters.1 kraut.1 \
	talkfilters.1 pansy.1 \
	talkfilters.1 pirate.1 \
	talkfilters.1 postmodern.1 \
	talkfilters.1 redneck.1 \
	talkfilters.1 valspeak.1 \
	talkfilters.1 warez.1
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
