# New ports collection makefile for:	messagewall-1.0.6
# Date created: 	24 Sep 2002
# Whom:			Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	messagewall
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.messagewall.org/download/
DISTNAME=	messagewall-${PORTVERSION}

MAINTAINER=	opr@bsdaemon.be
COMMENT=	Free SMTP PROXY with filtering

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring \
		${LOCALBASE}/include/firedns.h:${PORTSDIR}/dns/firedns

MAN1=		messagewall.1 messagewallctl.1 messagewallstats.1
MAN5=		messagewall.conf.5 messagewall_profiles.5
CONF1=		messagewall.conf

WRKSRC=		${WRKDIR}/messagewall
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DMESSAGEWALL_ALLOW_MULT_RCPT to allow multiple recipients"
	@${ECHO} "	 The profile for the first recipient will be applied to all"
	@${ECHO} "	 recipients of the message."
	@${ECHO} ""
	@${ECHO} "    -DWITH_ESMTP_SIZE_OPTION to allow messagewall to handle the"
	@${ECHO} "	 size option in MAIL FROM: <foo@bar.com> SIZE=12345678 (RFC1870)"
	@${ECHO} "	 This can safe a lot of bandwith, because it rejects any email,"
	@${ECHO} "	 if message size is greater than max message size."
	@${ECHO} ""

# Patch from "Quentin Guernsey" <quentin@wingateweb.com>
# for details see http://www.messagewall.org/cgi-bin/ezmlm-browse.cgi?command=showmsg&list=messagewall-discuss&month=200303&msgnum=921&threadid=lcjcimckfmdphlhpjjhn
.if defined(MESSAGEWALL_ALLOW_MULT_RCPT)
EXTRA_PATCHES+=	${PATCHDIR}/allow-multiple-recipients.patch
.endif

# Patch from "Michael Ranner" <mranner@inode.at>
# for details see http://www.ranner.jawa.at/messagewall.php
.if defined(WITH_ESMTP_SIZE_OPTION)
EXTRA_PATCHES+=	${PATCHDIR}/esmtpsize.patch
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/firemake.cflags \
		${WRKSRC}/firemake.ldflags
	${REINPLACE_CMD} -e 's|-lcrypto|-lcrypto ${PTHREAD_LIBS}|' \
		${WRKSRC}/firemake.libs

do-install:
	@${CP} ${WRKSRC}/messagewall ${PREFIX}/bin
	@${CP} ${WRKSRC}/messagewallctl ${PREFIX}/bin
	@${CP} ${WRKSRC}/messagewallstats ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/messagewall
	@${CP} ${WRKSRC}/virus.patterns ${PREFIX}/etc/messagewall/
	@${CP} -r ${WRKSRC}/profiles ${PREFIX}/etc/messagewall/
.for file in ${CONF1}
	@${CP} ${WRKSRC}/conf/${file} ${PREFIX}/etc/${file}.sample
.endfor
.for file in ${MAN1}
	@${CP} ${WRKSRC}/man/${file} ${PREFIX}/man/man1/
.endfor
.for file in ${MAN5}
	@${CP} ${WRKSRC}/man/${file} ${PREFIX}/man/man5/
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
