# New ports collection makefile for:	avmailgate
# Date created:		January 29, 2002
# Whom:			Oliver Breuninger <ob@breuninger.org>
#
# $FreeBSD$

#
# http://www.antivir.de/dateien/antivir/fuse6/fuse6.zip
#

PORTNAME=	avmailgate
PORTVERSION=	6.12.0.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.antivir.de/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	ob@breuninger.org
COMMENT=	AntiVir MailGate mail virusscanner

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-FreeBSD

NO_BUILD=	yes

BROKEN=		"Creates files in /etc and /usr/lib"

do-install:
	@${MKDIR} ${LOCALBASE}/etc/antivir
	@${MKDIR} /var/spool/avmailgate
	@${MKDIR} /var/spool/avmailgate/incoming
	@${MKDIR} /var/spool/avmailgate/outgoing
	@${MKDIR} /var/spool/avmailgate/rejected
	@${CHOWN} -R daemon:daemon /var/spool/avmailgate
	@${CHMOD} 0700 /var/spool/avmailgate
	@${CHMOD} 0700 /var/spool/avmailgate/incoming
	@${CHMOD} 0700 /var/spool/avmailgate/rejected
	@${CHMOD} 0700 /var/spool/avmailgate/outgoing
	@${LN} -fs ${LOCALBASE}/etc/antivir			/usr/lib/AntiVir
	@${LN} -fs ${LOCALBASE}/etc/antivir/avmailgate.acl	/etc/avmailgate.acl
	@${LN} -fs ${LOCALBASE}/etc/antivir/avmailgate.conf	/etc/avmailgate.conf
	@${CP} -p ${FILESDIR}/avmailgate.sh			${LOCALBASE}/etc/rc.d
	@${CP} -p ${WRKSRC}/antivir.vdf				${LOCALBASE}/etc/antivir
	@${CP} -p ${WRKSRC}/avmailgate/avgated			${LOCALBASE}/sbin
	@${CP} -p ${WRKSRC}/avmailgate/script/avq		${LOCALBASE}/sbin
	@${CP} -p ${WRKSRC}/avmailgate/avgatefwd		${LOCALBASE}/sbin
	@${CP} -p ${WRKSRC}/avmailgate/etc/avmailgate.*		${LOCALBASE}/etc/antivir
	@${CP} -p ${WRKSRC}/avmailgate/man/*.5			${LOCALBASE}/man/man5
	@${CP} -p ${WRKSRC}/avmailgate/man/*.8			${LOCALBASE}/man/man8

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "******************************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For full functionality of AntiVir MailGate you need an license key"
	@${ECHO_MSG} "from H+BEDV Datentechnik GmbH."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Put the file avmgate.key into the directory ${LOCALBASE}/etc/antivir"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For more information on AntiVir please visit our web site"
	@${ECHO_MSG} "http://www.antivir.de or http://www.hbedv.com."
	@${ECHO_MSG} "mailto: support@antivir.de"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "AntiVir is a registered trademark of H+BEDV Datentechnik GmbH"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "******************************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
