# New ports collection makefile for:	smail
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	smail
PORTVERSION=	3.2.0.111
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/ \
		ftp://ftp.planix.com/pub/Smail/ \
		ftp://ftp.fu-berlin.de/unix/mail/smail/

MAINTAINER=	torstenb@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident
.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

INSTALL_TARGET=	install installman

MAN1=		pathto.1 uuwho.1 uupath.1
MAN5=		smailconf.5 smail.5 smaildrct.5 smailmeth.5 smailqual.5 \
		smailrtrs.5 smailrtry.5 smailtrns.5
MAN8=		pathalias.8 mkdbm.8 mkline.8 mksort.8 mkaliases.8 smail.8 \
		mkpath.8 pathmerge.8 checkerr.8 getmap.8 mkhpath.8 savelog.8 \
		mkuuwho.8 mailq.8 sendmail.8 runq.8 rmail.8 rsmtp.8 smtpd.8 \
		newaliases.8 smailbug.8

post-install:
	@${ECHO_MSG} "If you want to replace sendmail with links to smail, type"
	@${ECHO_MSG} "the following command as \"root\":"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      make replace"

replace:
	@${ECHO_MSG} "===> Replacing sendmail"
	if [ -e /usr/sbin/sendmail ]; then \
		${MV} -f /usr/sbin/sendmail /usr/sbin/sendmail.BAK; \
		if [ -f /usr/sbin/sendmail.BAK ]; then \
			${CHMOD} 0 /usr/sbin/sendmail.BAK; \
		fi;\
	fi
	if [ -e ${PREFIX}/bin/smail ]; then \
		${CP} -fp ${PREFIX}/bin/smail /usr/sbin/sendmail; \
	fi
	if [ -f /usr/sbin/mailstats ]; then \
		${CHMOD} 0 /usr/sbin/mailstats; \
	fi
	if [ -e /usr/bin/newaliases ]; then \
		${MV} -f /usr/bin/newaliases /usr/bin/newaliases.BAK; \
		if [ -f /usr/bin/newaliases.BAK ]; then \
			${CHMOD} 0 /usr/bin/newaliases.BAK; \
		fi;\
	fi
	if [ -e ${PREFIX}/bin/newaliases ]; then \
		${CP} -fp ${PREFIX}/bin/newaliases /usr/bin/newaliases; \
	fi
	if [ -e /usr/bin/mailq ]; then \
		${MV} -f /usr/bin/mailq /usr/bin/mailq.BAK; \
		if [ -f /usr/bin/mailq.BAK ]; then \
			${CHMOD} 0 /usr/bin/mailq.BAK; \
		fi;\
	fi
	if [ -e ${PREFIX}/bin/mailq ]; then \
		${CP} -fp ${PREFIX}/bin/mailq /usr/bin/mailq; \
	fi

.include <bsd.port.mk>
