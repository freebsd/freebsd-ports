# New ports collection makefile for:	rancid
# Date created:		3 June 2002
# Whom:			Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	rancid
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/rancid/

MAINTAINER=	janos.mohacsi@bsd.hu

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect
RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/LockFile/Simple.pm:${PORTSDIR}/devel/p5-LockFile-Simple

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=			\
		--prefix=${PREFIX}/rancid

MANPREFIX=	${PREFIX}/rancid

MAN1=		lg_intro.1 par.1 do-diffs.1 alogin.1 blogin.1 clogin.1 \
		control_rancid.1 create_cvs.1 rancid.1 rancid_intro.1 \
		elogin.1 f10rancid.1 flogin.1 hlogin.1 hrancid.1 jlogin.1 \
		jrancid.1 francid.1 cat5rancid.1 erancid.1 mrancid.1 xrancid.1

MAN5=		env.5 lg.conf.5 cloginrc.5 router.db.5

CONFIG_FILES=	bin/env util/lg/lg.conf

post-install:
	@ ${SED} -e "s:%%INSTDIR%%:${PREFIX}/rancid:g" pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@ ${ECHO}
	@ ${CAT} ${PKGMESSAGE}
	@ ${ECHO}
.endif
.for file in ${CONFIG_FILES}
	@ if [ -f ${PREFIX}/rancid/${file}.new ] ; then \
	${ECHO} "WARNING: *** new ${file} file is installed as ${PREFIX}/rancid/${file}.new"; \
	${ECHO} "       : *** review ${file} for new/deprecated switches";  \
	fi
.endfor

.include <bsd.port.mk>
