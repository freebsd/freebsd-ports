# Created by: Andrey V. Pevnev <andrey@mgul.ac.ru>
# $FreeBSD$

PORTNAME=	mimedefang
PORTVERSION=	2.83
CATEGORIES=	mail
MASTER_SITES=	http://www.mimedefang.org/static/ \
		http://fossies.org/linux/misc/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Milter based anti-spam and anti-virus filtering program

LICENSE=	GPLv2

BUILD_DEPENDS=	\
	p5-IO-stringy>=0:devel/p5-IO-stringy \
	p5-MIME-Tools>=5.417:mail/p5-MIME-Tools \
	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
	spamassassin>=3.0:mail/spamassassin
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	CLAMAV EXAMPLES DOCS
OPTIONS_DEFAULT=	CLAMAV
CLAMAV_DESC=	Enable Clamav

USES=		perl5 shebangfix
perl_OLD_CMD=	perl
GNU_CONFIGURE=	yes

MIMEDEFANG_USER?=	mailnull
MIMEDEFANG_GROUP?=	mailnull
SPOOLDIR?=		/var/spool/MIMEDefang
QUARANTINEDIR?=		/var/spool/MD-Quarantine

CONFIGURE_ENV+=		PERL=${PERL}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc \
			--with-confsubdir=mimedefang \
			--with-user=${MIMEDEFANG_USER} \
			--with-spooldir=${SPOOLDIR} \
			--with-quarantinedir=${QUARANTINEDIR} \
			--with-ipheader \
			--prefix=${PREFIX}

SUB_FILES=	pkg-message

PLIST_SUB+=	USER="${MIMEDEFANG_USER}" \
		GROUP="${MIMEDEFANG_GROUP}" \
		MIMEDEFANG_RUNDIR="${SPOOLDIR}" \
		MIMEDEFANG_QUARANTINEDIR="${QUARANTINEDIR}"

CONFIG_FILES=	mimedefang-filter sa-mimedefang.cf mimedefang-ip-key

.include <bsd.port.options.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ARGS+=	--with-milterinc=${LOCALBASE}/include --with-milterlib=${LOCALBASE}/lib
.endif

CLAMAV_BUILD_DEPENDS+=		clamscan:security/clamav
CLAMAV_RUN_DEPENDS+=		clamscan:security/clamav
CLAMAV_CONFIGURE_ENABLE+=	antivirus clamav clamd

post-patch:
	@${REINPLACE_CMD} -e '/fgrep -e/d' ${WRKSRC}/configure

pre-install:
	@${REINPLACE_CMD} -e '/LOCAL_STATE_DIR/s,/var/lib,/var/db,' ${WRKSRC}/mimedefang.pl

post-install:
	@${REINPLACE_CMD} -e 's,%%CHMOD%%,${CHMOD},g' ${WRKSRC}/examples/init-script
	${INSTALL_SCRIPT} ${WRKSRC}/examples/init-script ${STAGEDIR}${PREFIX}/etc/rc.d/mimedefang
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}/
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${INSTALL_DATA} stream-by-domain-filter \
		suggested-minimum-filter-for-windows-clients README ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
