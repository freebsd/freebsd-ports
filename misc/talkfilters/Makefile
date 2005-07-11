# New ports collection makefile for:	talkfilters
# Date created:				03 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	talkfilters
PORTVERSION=	2.3.4
CATEGORIES=	misc
MASTER_SITES=	http://www2.dystance.net/software/talkfilters/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Set of filters to convert English text to various stereotyped dialects

CONFLICTS=	jive* chef* filters-*

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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
	@${ECHO_MSG} "original form. By downloading this software, you agree to accept"
	@${ECHO_MSG} "these terms.

post-patch:
	@${RM} -f ${WRKSRC}/*.info*

.include <bsd.port.mk>
