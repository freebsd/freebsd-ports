# New ports collection makefile for:	Quanta+
# Date created:				19 May 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quanta
PORTVERSION= 	2.0.1
PORTEPOCH=	1
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		css.tar.bz2 \
		html.tar.bz2 \
		javascript.tar.bz2 \
		php.tar.bz2
.endif

MAINTAINER=	jeremy@external.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
USE_XPM=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
USE_GMAKE=	yes

DOCS=		css html javascript php

pre-configure:
	@${PERL} -pi -e "s#lqt #lqt2 #g" ${WRKSRC}/quanta/Makefile.in
	@${PERL} -pi -e "s@automake@automake14@g" ${WRKSRC}/configure

	
post-configure:
	@${PERL} -pi -e "s@autoconf@autoconf213@g" ${WRKSRC}/Makefile
	@${PERL} -pi -e "s@moc@moc2@g" ${WRKSRC}/configure
	
post-install:
.if !defined(NOPORTDOCS)
.for doc in ${DOCS}
	cd ${WRKDIR}/${doc} && \
		${CP} -R ${doc} ${doc}.docrc ${PREFIX}/share/apps/quanta/doc
.endfor
	${CHOWN} -R root:wheel ${PREFIX}/share/apps/quanta/doc
	find ${PREFIX}/share/apps/quanta/doc -type f | xargs ${CHMOD} 444
.endif
	
.include <bsd.port.mk>
