# New ports collection makefile for:	rancid
# Date created:		3 June 2002
# Whom:			Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	rancid
PORTVERSION=	2.3.r1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/rancid/
DISTNAME=	${PORTNAME}-2.3.rc1

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Really Awesome New Cisco confIg Differ

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect
RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/LockFile/Simple.pm:${PORTSDIR}/devel/p5-LockFile-Simple

USE_PERL5=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=			\
		--prefix=${PREFIX}/rancid

MANPREFIX=	${PREFIX}/rancid

MAN1=		alogin.1 blogin.1 cat5rancid.1 clogin.1 control_rancid.1 \
		cssrancid.1 elogin.1 erancid.1 f10rancid.1 flogin.1 fnrancid.1 \
		francid.1 hlogin.1 hrancid.1 htlogin.1 htrancid.1 jerancid.1 \
		jlogin.1 jrancid.1 lg_intro.1 mrancid.1 nlogin.1 nrancid.1 \
		nslogin.1 nsrancid.1 par.1 prancid.1 rancid-cvs.1 rancid-run.1 \
		rancid.1 rancid_intro.1 rivlogin.1 rivrancid.1 tntlogin.1 \
		tntrancid.1 xrancid.1 zrancid.1

MAN5=		lg.conf.5 cloginrc.5 rancid.conf.5 router.db.5

OLDCONFIG_FILE1=	bin/env
OLDCONFIG_FILE2=	util/lg/lg.conf
NEWCONFIG_FILES=	etc/rancid.conf etc/lg.conf

pre-everything::
	@ ${ECHO} "Make sure your rancid repository is quit before upgrading; disable rancid cron jobs"

post-install:
	@ ${SED} -e "s:%%INSTDIR%%:${PREFIX}/rancid:g" pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@ ${ECHO}
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO}
.endif
.for file in ${NEWCONFIG_FILES}
	@ if [ -f ${PREFIX}/rancid/${file} ] ; then \
	${ECHO} "WARNING: *** new ${file} file is installed as ${PREFIX}/rancid/${file}.sample"; \
	${ECHO} "       : *** review ${file}.sample for new/deprecated switches or install in place ${file}";  \
	fi
.endfor
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${OLDCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/rancid/etc/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${OLDCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/rancid/etc/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE1} -o \
	-f ${PREFIX}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New CVS Repository will be stored ${PREFIX}/rancid/var "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

.include <bsd.port.mk>
