# New ports collection makefile for:	nntpcache
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $FreeBSD$
#

PORTNAME=	nntpcache
PORTVERSION=	2.4.0b2
CATEGORIES=	news
MASTER_SITES=	ftp://nntpcache.org/pub/nntpcache/ \
		ftp://ftp.ntnu.no/pub/unix/news/nntpcache/ \
		ftp://ftp.nethelp.no/pub/unix/news/ \
		ftp://suburbia.net/pub/nntpcache/

MAINTAINER=	nntpcache@nntpcache.org

BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgp

GNU_CONFIGURE=	TRUE
CONFIGURE_ARGS=	--localstatedir=/var/spool
MAN8=		nntpcached.8 newshound.8
DOCS=		AUTHORS ChangeLog FAQ FAQ.html HACKING \
		INSTALL LICENSING NEWS README README.INN VERSION

USE_GMAKE=	TRUE

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nntpcache
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/nntpcache; \
	done
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh \
		${PREFIX}/etc/rc.d/nntpcached.sh.sample
	@${SED} -e 's#/usr/local#${PREFIX}#' ${PKGMESSAGE}

hardlink-pgp-files:
	for i in ${PREFIX}/etc/nntpcache/*asc-dist ${PREFIX}/etc/nntpcache/*pgp-dist ; do \
		j=`${ECHO} $$i | ${SED} -e 's/-dist//'`; \
		if [ \! -f $$j ]; then \
			${LN} $$i $$j; \
		fi; \
	done

.include <bsd.port.mk>
