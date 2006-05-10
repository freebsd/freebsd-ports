# New ports collection makefile for:	messagewall-1.0.6
# Date created: 	24 Sep 2002
# Whom:			Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	messagewall
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	messagewall_${PORTVERSION}.orig

MAINTAINER=	opr@bsdaemon.be
COMMENT=	Free SMTP PROXY with filtering

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring \
		${LOCALBASE}/include/firedns.h:${PORTSDIR}/dns/firedns

MAN1=		messagewall.1 messagewallctl.1 messagewallstats.1
MAN5=		messagewall.conf.5 messagewall_profiles.5
CONF1=		messagewall.conf

OPTIONS=	BROKEN_PARAMETER "Detect unwanted extensions properly" off \
			ESMTP_SIZE_OPTION  "Handle the size option in MAIL FROM" off \
			MULTI_RCPT "Allow multiple recipients" off \
			PARANOIA "Detect faked mails from AOL, Hotmail" off \
			SPAM_STATS "Add spam statistics to messagewallstats" off
WRKSRC=		${WRKDIR}/messagewall-${PORTVERSION}
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# Patch from "Quentin Guernsey" <quentin@wingateweb.com>
# Allow multiple recipients, The profile for the first recipient will be
# applied to all recipients of the message.
# For details see http://www.messagewall.org/cgi-bin/ezmlm-browse.cgi?command=showmsg&list=messagewall-discuss&month=200303&msgnum=921&threadid=lcjcimckfmdphlhpjjhn
.if defined(WITH_MULTI_RCPT) || defined(MESSAGEWALL_ALLOW_MULT_RCPT)
EXTRA_PATCHES+=	${PATCHDIR}/allow-multiple-recipients.patch
.endif

# Patch from "Michael Ranner" <mranner@inode.at>
# Allow messagewall to handle the size option in MAIL FROM: <foo@bar.com>
# SIZE=12345678 (RFC1870). This can safe a lot of bandwith, because it rejects
# any email, if message size is greater than max message size.
# For details see http://www.ranner.jawa.at/messagewall.php
.if defined(WITH_ESMTP_SIZE_OPTION)
EXTRA_PATCHES+=	${PATCHDIR}/esmtpsize.patch
.endif

# Patch from "Collin Mulliner" <collin@mulliner.org>
# Some email viruses use badly composed mime attachments. MessageWall can't
# handle these by default. This breaks the detection of files with unwanted
# extensions. This patch removes this disadvantage.
# For details see http://www.mulliner.org/collin/patches.php
.if defined(WITH_BROKEN_PARAMETER)
EXTRA_PATCHES+=	${PATCHDIR}/broken_parameter_value.patch
.else
EXTRA_PATCHES+=	${PATCHDIR}/applemail.patch
.endif

# Patch from "Collin Mulliner" <collin@mulliner.org>
# This adds a check method to detect faked mails from big sites like Hotmail
# or AOL. It checks the by/from fields in the mail trace header "Received:"
# for a host name that matches the domain of the senders address.
# A new profile option is available to configure which domains to check.
# For details see http://www.mulliner.org/collin/patches.php
.if defined(WITH_PARANOIA)
EXTRA_PATCHES+=	${PATCHDIR}/paranoia.patch
.endif

# Patch from "Collin Mulliner" <collin@mulliner.org>
# Adds some nice spam statistics to the end of the output from
# messagewallstats
# For details see http://www.mulliner.org/collin/patches.php
.if defined(WITH_SPAM_STATS)
EXTRA_PATCHES+=	${PATCHDIR}/spam_stats.patch
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/firemake.cflags \
		${WRKSRC}/firemake.ldflags
	${REINPLACE_CMD} -e 's|-lcrypto|-lcrypto ${PTHREAD_LIBS}|' \
		${WRKSRC}/firemake.libs
.if defined(WITH_PARANOIA)
	@${RM} ${WRKSRC}/profiles/Warning.orig
.endif

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

.include <bsd.port.post.mk>
