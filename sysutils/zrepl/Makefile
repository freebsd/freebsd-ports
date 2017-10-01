# Created by: Nikolai Lifanov <lifanov@FreeBSD.org> and Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zrepl
PORTVERSION=	0.0.1
CATEGORIES=	sysutils

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	ZFS dataset replication tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_RC_SUBR=	zrepl
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/zrepl/zrepl
GH_TUPLE=	davecgh:go-spew:v1.1.0:go_spew/src/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.2:fsnotify/src/github.com/fsnotify/fsnotify \
		ftrvxmtrx:fd:c6d8003:fd/src/github.com/ftrvxmtrx/fd \
		go-logfmt:logfmt:v0.3.0:go_logfmt/src/github.com/go-logfmt/logfmt \
		go-yaml:yaml:eb3733d:go_yaml/src/github.com/go-yaml/yaml \
		hashicorp:hcl:68e816d:hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0:mousetrap/src/github.com/inconshreveable/mousetrap \
		jinzhu:copier:db4671f:copier/src/github.com/jinzhu/copier \
		kr:logfmt:b84e30a:logfmt/src/github.com/kr/logfmt \
		kr:pretty:cfb55aa:pretty/src/github.com/kr/pretty \
		kr:text:7cafcd8:text/src/github.com/kr/text \
		magiconair:properties:v1.7.3:properties/src/github.com/magiconair/properties \
		mitchellh:go-homedir:b8bc1bf:go_homedir/src/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:d0303fe:mapstructure/src/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:v0.2.0:go_buffruneio/src/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.0.0:go_toml/src/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:errors/src/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:go_difflib/src/github.com/pmezard/go-difflib \
		spf13:afero:ee1bd8e:afero/src/github.com/spf13/afero \
		spf13:cast:v1.1.0:cast/src/github.com/spf13/cast \
		spf13:cobra:b787445:cobra/src/github.com/spf13/cobra \
		spf13:jWalterWeatherman:12bd96e:jwalterweatherman/src/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.0:pflag/src/github.com/spf13/pflag \
		spf13:viper:v1.0.0:viper/src/github.com/spf13/viper \
		stretchr:testify:v1.1.4:testify/src/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}${PREFIX}/etc/syslog.d \
		${STAGEDIR}${PREFIX}/etc/zrepl
	${INSTALL_DATA} ${FILESDIR}/newsyslog-zrepl.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/zrepl.conf
	${INSTALL_DATA} ${FILESDIR}/syslog-zrepl.conf.sample ${STAGEDIR}${PREFIX}/etc/syslog.d/zrepl.conf.sample
	${INSTALL_DATA} ${FILESDIR}/zrepl.yml.sample ${STAGEDIR}${PREFIX}/etc/zrepl/zrepl.yml.sample

.include <bsd.port.mk>
