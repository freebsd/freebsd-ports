# New ports collection makefile for:   bld
# Date created:        12 October 2004
# Whom:                ob
#
# $FreeBSD$
#

PORTNAME=	bld
PORTVERSION=	0.3.4
CATEGORIES=	net
MASTER_SITES=	http://www.online.redhate.org/bld/ \
		http://olivier.beyssac.googlepages.com/

MAINTAINER=	obld@r14.freenix.org
COMMENT=	A blacklisting daemon

USE_RC_SUBR=	bld
MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/bld
PORTDOCS=	README README.postfix
MAN5=		bld_whitelist.conf.5 bld_acl.conf.5 bld.conf.5
MAN8=		bldsubmit.8 bld.8 bldquery.8 bldread.8 bldinsert.8 blddecr.8 \
		bld-pf_policy.8 bld-pf_log.pl.8 bld-mrtg.pl.8 \
		bld-will_spam_for_food.pl.8

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
