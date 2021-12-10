# Created by: Andrey V. Pevnev <andrey@mgul.ac.ru>

PORTNAME=	mimedefang
PORTVERSION=	2.84
PORTREVISION=	1

CATEGORIES=	mail
MASTER_SITES=	http://www.mimedefang.org/static/ \
		http://fossies.org/linux/misc/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Milter based anti-spam and anti-virus filtering program

LICENSE=	GPLv2

BUILD_DEPENDS=	\
	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
	p5-MIME-Tools>=5.417:mail/p5-MIME-Tools \
	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
	spamassassin>=3.0:mail/spamassassin
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe perl5 shebangfix
perl_OLD_CMD=	perl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc \
			--with-confsubdir=mimedefang \
			--with-user=${MIMEDEFANG_USER} \
			--with-spooldir=${SPOOLDIR} \
			--with-quarantinedir=${QUARANTINEDIR} \
			--with-ipheader \
			--prefix=${PREFIX}
CONFIGURE_ENV+=		PERL=${PERL}

SUB_FILES=	pkg-message

PLIST_SUB+=	USER="${MIMEDEFANG_USER}" \
		GROUP="${MIMEDEFANG_GROUP}" \
		MIMEDEFANG_RUNDIR="${SPOOLDIR}" \
		MIMEDEFANG_QUARANTINEDIR="${QUARANTINEDIR}"

MIMEDEFANG_USER?=	mailnull
MIMEDEFANG_GROUP?=	mailnull
SPOOLDIR?=		/var/spool/MIMEDefang
QUARANTINEDIR?=		/var/spool/MD-Quarantine
CONFIG_FILES=	mimedefang-filter sa-mimedefang.cf mimedefang-ip-key

OPTIONS_DEFINE=	CLAMAV DOCS EXAMPLES
OPTIONS_DEFAULT=	CLAMAV

CLAMAV_DESC=	Enable Clamav

CLAMAV_BUILD_DEPENDS=		clamscan:security/clamav
CLAMAV_RUN_DEPENDS=		clamscan:security/clamav
CLAMAV_CONFIGURE_ENABLE=	antivirus clamav clamd

.include <bsd.port.options.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

CONFIGURE_ARGS+=	--with-milterinc=${MILTERBASE}/include --with-milterlib=${MILTERBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/fgrep -e/d' ${WRKSRC}/configure

pre-install:
	@${REINPLACE_CMD} -e '/LOCAL_STATE_DIR/s,/var/lib,/var/db,' ${WRKSRC}/mimedefang.pl

post-install:
	@${REINPLACE_CMD} -e 's,%%CHMOD%%,${CHMOD},g' ${WRKSRC}/examples/init-script
	${INSTALL_SCRIPT} ${WRKSRC}/examples/init-script ${STAGEDIR}${PREFIX}/etc/rc.d/mimedefang

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ && ${INSTALL_DATA} stream-by-domain-filter \
		suggested-minimum-filter-for-windows-clients README ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
