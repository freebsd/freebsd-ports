# New ports collection makefile for:	mimedefang
# Date created:				13 May 2002
# Whom:					Andrey V. Pevnev <andrey@mgul.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	mimedefang
PORTVERSION=	2.63
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://www.mimedefang.org/static/

MAINTAINER=	wes@FreeBSD.org
COMMENT=	Milter based anti-spam and anti-virus filtering program

BUILD_DEPENDS=	\
	${PERL_SITELIBDIR}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	p5-MIME-Tools>=5.417:${PORTSDIR}/mail/p5-MIME-Tools \
	${PERL_SITELIBDIR}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${PERL_SITELIBDIR}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${PERL_SITELIBDIR}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
	${PERL_SITELIBDIR}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_SITELIBDIR=	${SITE_PERL}
GNU_CONFIGURE=	yes

MAILUSER?=		mailnull
SPOOLDIR?=		/var/spool/MIMEDefang
QUARANTINEDIR?=	/var/spool/MD-Quarantine

CONFIGURE_ENV+=		PERL=${PERL}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/mimedefang \
			--with-confsubdir= \
			--with-user=${MAILUSER} \
			--with-spooldir=${SPOOLDIR} \
			--with-quarantinedir=${QUARANTINEDIR} \
			--prefix=${PREFIX}

MAN5=	mimedefang-filter.5
MAN7=	mimedefang-notify.7 mimedefang-protocol.7
MAN8=	mimedefang.8 mimedefang.pl.8 mimedefang-multiplexor.8 \
	md-mx-ctrl.8 watch-mimedefang.8 watch-multiple-mimedefangs.8

.include <bsd.port.pre.mk>

.if !exists( /usr/include/libmilter/mfapi.h )
BUILD_DEPENDS+=	${LOCALBASE}/include/libmilter/mfapi.h:${PORTSDIR}/mail/sendmail
.endif

.if exists( /usr/local/include/libmilter/mfapi.h )
CONFIGURE_ARGS+= --with-milterinc=${LOCALBASE}/include
CONFIGURE_ARGS+= --with-milterlib=${LOCALBASE}/lib
.endif

pre-install:
	@${REINPLACE_CMD} -e '/LOCAL_STATE_DIR/s,/var/lib,/var/db,' ${WRKSRC}/mimedefang.pl

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

.include <bsd.port.post.mk>
