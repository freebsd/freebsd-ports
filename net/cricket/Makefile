# New ports collection makefile for:	Cricket
# Date created:		20 November 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	cricket
PORTVERSION=	1.0.4.p1
CATEGORIES=	net
MASTER_SITES=	http://cricket.sourceforge.net/download/beta/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-pre/}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net/p5-SNMP_Session \
		${SITE_PERL_ARCH}/RRDs.pm:${PORTSDIR}/net/rrdtool \
		${SITE_PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
SITE_PERL_ARCH=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

HAS_CONFIGURE=	yes
USE_PERL5=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	VERSION=${PORTVERSION}
CRICKET_USER=	cricket
CRICKET_GROUP=	www

do-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
	@${MKDIR} -m 755 ${PREFIX}/cricket/cricket-${PORTVERSION}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/cricket/cricket-${PORTVERSION}
	@${FIND} ${PREFIX}/cricket/cricket-${PORTVERSION} -name \*.orig -or \
		-name \*.bak | ${XARGS} ${RM} -f
	${CHOWN} -R ${CRICKET_USER}:${CRICKET_GROUP} ${PREFIX}/cricket
	@if [ -L ${PREFIX}/cricket/cricket ]; then \
		${ECHO} "Updating ${PREFIX}/cricket/cricket symbolic link" ; \
		${RM} ${PREFIX}/cricket/cricket ; \
	fi
	${LN} -s ${PREFIX}/cricket/cricket-${PORTVERSION} \
		${PREFIX}/cricket/cricket
	@if [ -f ${LOCALBASE}/cricket/compile ] ; then \
		${ECHO} "You should migrate manually to use new cricket" ; \
		${ECHO} "installation scheme." ; \
	fi

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/cricket-conf.pl.sample \
		>${PREFIX}/etc/cricket-conf.pl.dist 
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${FILESDIR}/pkg-message.in > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
