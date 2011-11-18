# New ports collection makefile for:	Cricket
# Date created:		20 November 1999
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	cricket
PORTVERSION=	1.0.5
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high performance, extremely flexible monitoring system

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate

USE_PERL5=	yes
HAS_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}
SUB_FILES=	pkg-message

# UID and username comes from ports/UIDs.
USERS=	cricket
GROUPS=	www

.include <bsd.port.pre.mk>

# A reliable version of Time::HiRes is included with perl 5.8.7 and later.
.if ${PERL_LEVEL} < 500807
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/home/cricket,${PREFIX},g' \
		${WRKSRC}/cricket-conf.pl.sample
	@${REINPLACE_CMD} -e 's,/usr/local/net/bin/ssh,/usr/bin/ssh,g' \
		${WRKSRC}/sample-config/news-server/Defaults

do-install:
	@${MKDIR} -m 755 ${PREFIX}/cricket/cricket-${PORTVERSION}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/cricket/cricket-${PORTVERSION}
	@${FIND} ${PREFIX}/cricket/cricket-${PORTVERSION} -name \*.orig -or \
		-name \*.bak | ${XARGS} ${RM} -f
	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/cricket
	@if [ -L ${PREFIX}/cricket/cricket ]; then \
		${ECHO_MSG} "Updating ${PREFIX}/cricket/cricket symbolic link"; \
		${RM} ${PREFIX}/cricket/cricket; \
	fi
	${LN} -s ${PREFIX}/cricket/cricket-${PORTVERSION} \
		${PREFIX}/cricket/cricket
	@if [ -f ${LOCALBASE}/cricket/compile ] ; then \
		${ECHO_MSG} "You should migrate manually to use new cricket"; \
		${ECHO_MSG} "installation scheme."; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/cricket-conf.pl.sample ${PREFIX}/etc/cricket-conf.pl.dist

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
