# New ports collection makefile for:	mimedefang
# Date created:				13 May 2002
# Whom:					Andrey V. Pevnev <andrey@mgul.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	mimedefang
PORTVERSION=	2.24
CATEGORIES=	mail
MASTER_SITES=	http://www.roaringpenguin.com/mimedefang/

MAINTAINER=	andrey@mgul.ac.ru

BUILD_DEPENDS=	\
	${PERL_SITELIBDIR}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${PERL_SITELIBDIR}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${PERL_SITELIBDIR}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${PERL_SITELIBDIR}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${PERL_SITELIBDIR}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
	${PERL_SITELIBDIR}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin

USE_PERL5=	yes
USE_REINPLACE=	yes
PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/mimedefang \
			--with-confsubdir= \
			--with-user=mailnull

MAN5=	mimedefang-filter.5
MAN7=	mimedefang-protocol.7
MAN8=	mimedefang.8 mimedefang.pl.8 mimedefang-multiplexor.8 \
	md-mx-ctrl.8 watch-mimedefang.8

.if !exists( /usr/include/libmilter/mfapi.h )
BUILD_DEPENDS+=	${LOCALBASE}/include/libmilter/mfapi.h:${PORTSDIR}/mail/sendmail
.endif

post-install:
	@${REINPLACE_CMD} -e 's,# MX_USER=,MX_USER=,g ; \
			s,# MX_MAX_RSS=,MX_MAX_RSS=,g ; \
			s,# MX_MAX_AS=,MX_MAX_AS=,g' ${WRKSRC}/examples/init-script
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/init-script ${PREFIX}/etc/rc.d/mimedefang.sh-dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/stream-by-domain-filter ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/suggested-minimum-filter-for-windows-clients ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
