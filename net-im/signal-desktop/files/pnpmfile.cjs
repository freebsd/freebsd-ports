module.exports = {
  hooks: {
    readPackage: (pkg) => {
      delete pkg.optionalDependencies['fs-xattr']
      delete pkg.optionalDependencies['@signalapp/mock-server']
      return pkg
    }
  }
}
