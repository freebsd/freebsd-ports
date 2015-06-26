# $FreeBSD$

PORTNAME=	vault
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for securely accessing secrets

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp:DEFAULT,consul,errwrap,gomultierror,hcl,awssdkgo,syslog,lru,logutils \
	mitchellh:cli,copystructure,gohomedir,mapstructure,reflectwalk \
	vaughan0:goini golang:crypto,oauth2,net armon:gometrics,goradix \
	go-sql-driver:mysql kardianos:osext lib:pq ryanuber:columnize samuel:zk vanackere:ldap,asn google:querystring,github
GH_PROJECT=	consul:consul errwrap:errwrap go-multierror:gomultierror \
	hcl:hcl cli:cli copystructure:copystructure go-homedir:gohomedir \
	mapstructure:mapstructure osext:osext \
	reflectwalk:reflectwalk go-ini:goini aws-sdk-go:awssdkgo \
	crypto:crypto \
	oauth2:oauth2 \
	net:net \
	go-metrics:gometrics go-radix:goradix mysql:mysql go-github:github go-syslog:syslog golang-lru:lru \
	logutils:logutils pq:pq columnize:columnize go-zookeeper:zk ldap:ldap go-querystring:querystring \
	asn1-ber:asn
GH_TAGNAME=	7062ecc:consul 7554cd9:errwrap fcdddc3:gomultierror \
	513e04c:hcl 6cc8bc5:cli 6fc6626:copystructure \
	1f6da4a:gohomedir 442e588:mapstructure 242be0c:reflectwalk \
	a98ad7e:goini 5943553:crypto \
	ec6d5d7:oauth2 a8c6199:net \
	a54701e:gometrics 0bab926:goradix a197e5d:mysql 0aaa85b:github e6ea0192:awssdkgo 42a2b57:syslog d85392d:lru 367a65d:logutils 8fef92e:osext 8910d1c:pq \
	44cb4788:columnize d0e0d8e1:zk e29b797:ldap 547ef5a:querystring 295c7b2:asn

STRIP=		# stripping can break go binaries

USE_RC_SUBR=	vault

USERS=		vault
GRUOPS=		vault

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in Godeps LICENSE Makefile README.md api audit builtin cli command \
	helper http logical main.go main_test.go make.bat physical scripts \
	shamir test vault website CHANGELOG.md .gitignore .travis.yml
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/vaughan0
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/go-sql-driver
	@${MKDIR} ${WRKSRC}/src/github.com/google
	@${MKDIR} ${WRKSRC}/src/github.com/vanackere
	@${MKDIR} ${WRKSRC}/src/github.com/samuel
	@${MKDIR} ${WRKSRC}/src/github.com/ryanuber
	@${MKDIR} ${WRKSRC}/src/github.com/lib
	@${MKDIR} ${WRKSRC}/src/github.com/kardianos
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_osext} ${WRKSRC}/src/github.com/kardianos/osext
	@${MV} ${WRKSRC_reflectwalk} ${WRKSRC}/src/github.com/mitchellh/reflectwalk
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_gohomedir} ${WRKSRC}/src/github.com/mitchellh/go-homedir
	@${MV} ${WRKSRC_copystructure} ${WRKSRC}/src/github.com/mitchellh/copystructure
	@${MV} ${WRKSRC_cli} ${WRKSRC}/src/github.com/mitchellh/cli
	@${MV} ${WRKSRC_hcl} ${WRKSRC}/src/github.com/hashicorp/hcl
	@${MV} ${WRKSRC_gomultierror} ${WRKSRC}/src/github.com/hashicorp/go-multierror
	@${MV} ${WRKSRC_errwrap} ${WRKSRC}/src/github.com/hashicorp/errwrap
	@${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul
	@${MV} ${WRKSRC_awssdkgo} ${WRKSRC}/src/github.com/hashicorp/aws-sdk-go
	@${MV} ${WRKSRC_goini} ${WRKSRC}/src/github.com/vaughan0/go-ini
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${CP} -r ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/github.com/golang/net
	@${MV} ${WRKSRC_gometrics} ${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_goradix} ${WRKSRC}/src/github.com/armon/go-radix
	@${MV} ${WRKSRC_mysql} ${WRKSRC}/src/github.com/go-sql-driver/mysql
	@${MV} ${WRKSRC_github} ${WRKSRC}/src/github.com/google/go-github
	@${MV} ${WRKSRC_ldap} ${WRKSRC}/src/github.com/vanackere/ldap
	@${MV} ${WRKSRC_zk} ${WRKSRC}/src/github.com/samuel/go-zookeeper
	@${MV} ${WRKSRC_columnize} ${WRKSRC}/src/github.com/ryanuber/columnize
	@${MV} ${WRKSRC_pq} ${WRKSRC}/src/github.com/lib/pq
	@${MV} ${WRKSRC_lru} ${WRKSRC}/src/github.com/hashicorp/golang-lru
	@${MV} ${WRKSRC_logutils} ${WRKSRC}/src/github.com/hashicorp/logutils
	@${MV} ${WRKSRC_syslog} ${WRKSRC}/src/github.com/hashicorp/go-syslog
	@${MV} ${WRKSRC_querystring} ${WRKSRC}/src/github.com/google/go-querystring
	@${MV} ${WRKSRC_asn} ${WRKSRC}/src/github.com/vanackere/asn1-ber

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
