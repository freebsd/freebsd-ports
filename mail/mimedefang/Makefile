# New ports collection makefile for:	mimedefang
# Date created:				13 May 2002
# Whom:					Andrey V. Pevnev <andrey@mgul.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	mimedefang
PORTVERSION=	2.68
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mimedefang.org/static/

MAINTAINER=	wes@FreeBSD.org
COMMENT=	Milter based anti-spam and anti-virus filtering program

BUILD_DEPENDS=	\
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	p5-MIME-Tools>=5.417:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
	${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAILUSER?=		mailnull
SPOOLDIR?=		/var/spool/MIMEDefang
QUARANTINEDIR?=	/var/spool/MD-Quarantine

CONFIGURE_ENV+=		PERL=${PERL}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc \
			--with-confsubdir=mimedefang \
			--with-user=${MAILUSER} \
			--with-spooldir=${SPOOLDIR} \
			--with-quarantinedir=${QUARANTINEDIR} \
			--prefix=${PREFIX}

.if defined (MIMEDEFANG_DISABLE_CLAMAV)
CONFIGURE_ARGS+=	--disable-antivirus \
			--disable-clamav \
			--disable-clamd
.endif

MAN5=	mimedefang-filter.5
MAN7=	mimedefang-notify.7 mimedefang-protocol.7
MAN8=	mimedefang.8 mimedefang.pl.8 mimedefang-multiplexor.8 \
	md-mx-ctrl.8 watch-mimedefang.8 watch-multiple-mimedefangs.8

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if !exists( /usr/include/libmilter/mfapi.h )
BUILD_DEPENDS+=	${LOCALBASE}/include/libmilter/mfapi.h:${PORTSDIR}/mail/sendmail
.endif

.if exists( ${LOCALBASE}/include/libmilter/mfapi.h )
CONFIGURE_ARGS+=	--with-milterinc=${LOCALBASE}/include --with-milterlib=${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} -e '/fgrep -e/d' ${WRKSRC}/configure

pre-install:
	@${REINPLACE_CMD} -e '/LOCAL_STATE_DIR/s,/var/lib,/var/db,' ${WRKSRC}/mimedefang.pl

post-install:
	@${REINPLACE_CMD} -e 's,%%CHMOD%%,${CHMOD},g' ${WRKSRC}/examples/init-script
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/init-script ${PREFIX}/etc/rc.d/mimedefang
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${INSTALL_DATA} stream-by-domain-filter \
		suggested-minimum-filter-for-windows-clients README ${EXAMPLESDIR}/
.endif
	@[ -d ${SPOOLDIR} ] && ${CHGRP} ${MAILUSER} ${SPOOLDIR}
	@[ -d ${QUARANTINEDIR} ] && ${CHGRP} ${MAILUSER} ${QUARANTINEDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
