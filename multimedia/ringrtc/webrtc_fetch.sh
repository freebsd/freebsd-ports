#!/bin/sh

WEBRTC_REV=5993a

base_url="https://chromium.googlesource.com/chromium/src/base.git/+archive/"
boringssl_url="https://boringssl.googlesource.com/boringssl.git/+archive/"
build_url="https://chromium.googlesource.com/chromium/src/build.git/+archive/"
buildtools_url="https://chromium.googlesource.com/chromium/src/buildtools.git/+archive/"
catapult_url="https://chromium.googlesource.com/catapult.git/+archive/"
icu_url="https://chromium.googlesource.com/chromium/deps/icu.git/+archive/"
libjpeg_turbo_url="https://chromium.googlesource.com/chromium/deps/libjpeg_turbo.git/+archive/"
libsrtp_url="https://chromium.googlesource.com/chromium/deps/libsrtp.git/+archive/"
libvpx_url="https://chromium.googlesource.com/webm/libvpx.git/+archive/"
libyuv_url="https://chromium.googlesource.com/libyuv/libyuv.git/+archive/"
nasm_url="https://chromium.googlesource.com/chromium/deps/nasm.git/+archive/"
testing_url="https://chromium.googlesource.com/chromium/src/testing.git/+archive/"
third_party_url="https://chromium.googlesource.com/chromium/src/third_party.git/+archive/"

fetch -q -o /tmp/DEPS https://raw.githubusercontent.com/signalapp/webrtc/${WEBRTC_REV}/DEPS

base_hash=$(grep 'base@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BASE_REV=\t${base_hash}\n"
printf "BASE_REV=\t${base_hash}\n" | portedit merge -i Makefile

boringssl_hash=$(grep 'boringssl.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BORINGSSL_REV=\t${boringssl_hash}\n"
printf "BORINGSSL_REV=\t${boringssl_hash}\n" | portedit merge -i Makefile

build_hash=$(grep 'build@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BUILD_REV=\t${build_hash}\n"
printf "BUILD_REV=\t${build_hash}\n" | portedit merge -i Makefile

buildtools_hash=$(grep 'buildtools@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "BUILDTOOLS_REV=\t${buildtools_hash}\n"
printf "BUILDTOOLS_REV=\t${buildtools_hash}\n" | portedit merge -i Makefile

catapult_hash=$(grep 'catapult.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "CATAPULT_REV=\t${catapult_hash}\n"
printf "CATAPULT_REV=\t${catapult_hash}\n" | portedit merge -i Makefile

icu_hash=$(grep 'icu.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "ICU_REV=\t${icu_hash}\n"
printf "ICU_REV=\t${icu_hash}\n" | portedit merge -i Makefile

libjpeg_turbo_hash=$(grep 'libjpeg_turbo.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBJPEG_TURBO_REV=\t${libjpeg_turbo_hash}\n"
printf "LIBJPEG_TURBO_REV=\t${libjpeg_turbo_hash}\n" | portedit merge -i Makefile

libsrtp_hash=$(grep 'libsrtp.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBSRTP_REV=\t${libsrtp_hash}\n"
printf "LIBSRTP_REV=\t${libsrtp_hash}\n" | portedit merge -i Makefile

libvpx_hash=$(grep 'libvpx.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBVPX_REV=\t${libvpx_hash}\n"
printf "LIBVPX_REV=\t${libvpx_hash}\n" | portedit merge -i Makefile

libyuv_hash=$(grep 'libyuv.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "LIBYUV_REV=\t${libyuv_hash}\n"
printf "LIBYUV_REV=\t${libyuv_hash}\n" | portedit merge -i Makefile

nasm_hash=$(grep 'nasm.git@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "NASM_REV=\t${nasm_hash}\n"
printf "NASM_REV=\t${nasm_hash}\n" | portedit merge -i Makefile

testing_hash=$(grep 'testing@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "TESTING_REV=\t${testing_hash}\n"
printf "TESTING_REV=\t${testing_hash}\n" | portedit merge -i Makefile

third_party_hash=$(grep 'third_party@' /tmp/DEPS | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
printf "THIRD_PARTY_REV=\t${third_party_hash}\n"
printf "THIRD_PARTY_REV=\t${third_party_hash}\n" | portedit merge -i Makefile

#exit

mkdir dist_tmp
echo "fetch -o dist_tmp/base-${base_hash}.tar.gz ${base_url}${base_hash}.tar.gz"
echo "fetch -o dist_tmp/boringssl-${boringssl_hash}.tar.gz ${boringssl_url}${boringssl_hash}.tar.gz"
echo "fetch -o dist_tmp/build-${build_hash}.tar.gz ${build_url}${build_hash}.tar.gz"
echo "fetch -o dist_tmp/buildtools-${buildtools_hash}.tar.gz ${buildtools_url}${buildtools_hash}.tar.gz"
echo "fetch -o dist_tmp/catapult-${catapult_hash}.tar.gz ${catapult_url}${catapult_hash}.tar.gz"
echo "fetch -o dist_tmp/icu-${icu_hash}.tar.gz ${icu_url}${icu_hash}.tar.gz"
echo "fetch -o dist_tmp/libjpeg_turbo-${libjpeg_turbo_hash}.tar.gz ${libjpeg_turbo_url}${libjpeg_turbo_hash}.tar.gz"
echo "fetch -o dist_tmp/libsrtp-${libsrtp_hash}.tar.gz ${libsrtp_url}${libsrtp_hash}.tar.gz"
echo "fetch -o dist_tmp/libvpx-${libvpx_hash}.tar.gz ${libvpx_url}${libvpx_hash}.tar.gz"
echo "fetch -o dist_tmp/libyuv-${libyuv_hash}.tar.gz ${libyuv_url}${libyuv_hash}.tar.gz"
echo "fetch -o dist_tmp/nasm-${nasm_hash}.tar.gz ${nasm_url}${nasm_hash}.tar.gz"
echo "fetch -o dist_tmp/testing-${testing_hash}.tar.gz ${testing_url}${testing_hash}.tar.gz"
echo "fetch -o dist_tmp/third_party-${third_party_hash}.tar.gz ${third_party_url}${third_party_hash}.tar.gz"

mkdir -p base boringssl build buildtools catapult icu libjpeg_turbo libsrtp libvpx libyuv nasm testing third_party
tar xf dist_tmp/base-${base_hash}.tar.gz -C base
tar xf dist_tmp/boringssl-${boringssl_hash}.tar.gz -C boringssl
tar xf dist_tmp/build-${build_hash}.tar.gz -C build
tar xf dist_tmp/buildtools-${buildtools_hash}.tar.gz -C buildtools
tar xf dist_tmp/catapult-${catapult_hash}.tar.gz -C catapult
tar xf dist_tmp/icu-${icu_hash}.tar.gz -C icu
tar xf dist_tmp/libjpeg_turbo-${libjpeg_turbo_hash}.tar.gz -C libjpeg_turbo
tar xf dist_tmp/libsrtp-${libsrtp_hash}.tar.gz -C libsrtp
tar xf dist_tmp/libvpx-${libvpx_hash}.tar.gz -C libvpx
tar xf dist_tmp/libyuv-${libyuv_hash}.tar.gz -C libyuv
tar xf dist_tmp/nasm-${nasm_hash}.tar.gz -C nasm
tar xf dist_tmp/testing-${testing_hash}.tar.gz -C testing
tar xf dist_tmp/third_party-${third_party_hash}.tar.gz -C third_party

mkdir dist_good
tar czf dist_good/base-${base_hash}.tar.gz base
tar czf dist_good/boringssl-${boringssl_hash}.tar.gz boringssl
tar czf dist_good/build-${build_hash}.tar.gz build
tar czf dist_good/buildtools-${buildtools_hash}.tar.gz buildtools
tar czf dist_good/catapult-${catapult_hash}.tar.gz catapult
tar czf dist_good/icu-${icu_hash}.tar.gz icu
tar czf dist_good/libjpeg_turbo-${libjpeg_turbo_hash}.tar.gz libjpeg_turbo
tar czf dist_good/libsrtp-${libsrtp_hash}.tar.gz libsrtp
tar czf dist_good/libvpx-${libvpx_hash}.tar.gz libvpx
tar czf dist_good/libyuv-${libyuv_hash}.tar.gz libyuv
tar czf dist_good/nasm-${nasm_hash}.tar.gz nasm
tar czf dist_good/testing-${testing_hash}.tar.gz testing
tar czf dist_good/third_party-${third_party_hash}.tar.gz third_party

rm -rf base boringssl build buildtools catapult icu libjpeg_turbo libsrtp libvpx libyuv nasm testing third_party
