# New ports collection makefile for:	nntpcache
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $FreeBSD$
#

PORTNAME=	nntpcache
PORTVERSION=	2.4.0b5
CATEGORIES=	news
MASTER_SITES=	ftp://nntpcache.org/pub/nntpcache/ \
		ftp://ftp.nethelp.no/pub/news/ \
		ftp://ftp.netsw.org/net/news/proxy/nntpcache/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14

# This may be set interactively at install-time.  NNTPCache will
# cache news articles and related data in ${SPOOLDIR}/nntpcache.
SPOOLDIR?=	/var/spool

NO_CDROM=	Free for individuals and non-military, non-profit organisations only
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${SPOOLDIR}
NNTPSPOOLDIR?=	${SPOOLDIR}/${PORTNAME}
PLIST_SUB+=	SPOOLDIR=${NNTPSPOOLDIR}
CPIO=		cpio --quiet -pdum -R
MAN8=		nntpcached.8 newshound.8
DOCS=		AUTHORS ChangeLog FAQ FAQ.html HACKING HTML \
		INSTALL LICENSING NEWS README README.INN VERSION

post-patch:
	@${PERL} -pi -e 's,AUTOMAKE=automake,AUTOMAKE=automake14,' \
		${WRKSRC}/configure

post-install:
	@ ${MKDIR} ${PREFIX}/etc/rc.d
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${FILESDIR}/nntpcached.rc \
	  > ${WRKDIR}/nntpcached.sh
.if !defined(BATCH)
	@ ${ECHO} "Installing ${PREFIX}/etc/rc.d/nntpcached.sh startup file"
.endif
	@ ${INSTALL_SCRIPT} -m 751 ${WRKDIR}/nntpcached.sh \
	  ${PREFIX}/etc/rc.d
	@ ${MKDIR} ${NNTPSPOOLDIR} && ${CHMOD} 750 ${NNTPSPOOLDIR}
	@ ${CP} ${PREFIX}/etc/${PORTNAME}/VERSION ${NNTPSPOOLDIR} && \
	  ${CHMOD} 640 ${NNTPSPOOLDIR}/VERSION
	@ ${CHOWN} -R news:news ${NNTPSPOOLDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && find ${DOCS} \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
